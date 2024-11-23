#!/bin/bash
make all clean
rm -rf outs.txt
rm -rf outs2.txt
while read uwu; do
	echo -e "$uwu" | ./minishell 2>&1 | cat >>outs.txt
	echo -e "$uwu" | bash 2>&1 | cat >>outs2.txt
done < tests.sh