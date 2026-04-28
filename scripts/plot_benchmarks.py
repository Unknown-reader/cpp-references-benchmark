#!/usr/bin/env python3
"""
Скрипт для парсинга вывода Google Benchmark и генерации сравнительного графика.
Запускается из CI после прогона бенчмарков.
"""

import sys
import re
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

def parse_benchmark_output(output_text):
    results = {}

    pattern = r'^\s*(\S+)\s+(\d+(?:\.\d+)?)\s+ns\s+(\d+(?:\.\d+)?)\s+ns'
    for line in output_text.splitlines():
        match = re.match(pattern, line)
        if match:
            name = match.group(1)
            cpu_time = float(match.group(3))
            results[name] = cpu_time
    return results

def create_plot(results):
    pairs = [
        ('Vector 1k', 'SumVectorFixture/BM_SumVectorPassedByCopy/1000', 'SumVectorFixture/BM_SumVectorPassedByConstRef/1000'),
        ('Vector 1M', 'SumVectorFixture/BM_SumVectorPassedByCopy/1000000', 'SumVectorFixture/BM_SumVectorPassedByConstRef/1000000'),
        ('Short String', 'ShortStrProcessFixture/BM_ProcessShortStrPassedByCopy', 'ShortStrProcessFixture/BM_ProcessShortStrPassedByConstRef'),
        ('Long String', 'LongStrProcessFixture/BM_ProcessLongStrPassedByCopy', 'LongStrProcessFixture/BM_ProcessLongStrPassedByConstRef'),
        ('BigObject', 'BigObjectProcessFixture/BM_ProcessBigObjectPassedByCopy', 'BigObjectProcessFixture/BM_ProcessBigObjectPassedByConstRef'),
    ]

    valid_pairs = []
    for label, copy_key, ref_key in pairs:
        if copy_key in results and ref_key in results:
            valid_pairs.append((label, results[copy_key], results[ref_key]))

    if not valid_pairs:
        print("No benchmark data found!")
        return False

    n = len(valid_pairs)
    fig, axes = plt.subplots(n, 1, figsize=(10, 3 * n), sharex=False)
    if n == 1:
        axes = [axes]

    for ax, (label, copy_val, ref_val) in zip(axes, valid_pairs):
        x = np.arange(2)
        bars = ax.bar(x, [copy_val, ref_val], width=0.5,
                      color=['#e74c3c', '#2ecc71'], edgecolor=['#c0392b', '#27ae60'])
        ax.set_xticks(x)
        ax.set_xticklabels(['Pass by Value', 'Pass by const&'])
        ax.set_ylabel('CPU Time (ns)')
        ax.set_title(label, fontsize=11)
        ax.grid(axis='y', linestyle='--', alpha=0.3)

        for bar in bars:
            height = bar.get_height()
            ax.text(bar.get_x() + bar.get_width() / 2., height * 1.02,
                    f'{height:,.2f}', ha='center', va='bottom', fontsize=8)

    plt.tight_layout()
    output_path = Path('benchmark_chart.png')
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    print(f"Chart saved to {output_path}")
    return True

def main():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            output = f.read()
    else:
        output = sys.stdin.read()
    
    results = parse_benchmark_output(output)
    if not results:
        print("Error: No benchmark results found in input", file=sys.stderr)
        sys.exit(1)
    
    print(f"Parsed {len(results)} benchmark results")
    if create_plot(results):
        print("Plot generated successfully")
    else:
        print("Failed to generate plot", file=sys.stderr)
        sys.exit(1)

if __name__ == '__main__':
    main()