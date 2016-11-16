#!/usr/bin/env python
__author__ = 'krille0x7c2'

chess_set = [1,1,2,2,2,8]

str_in = [int(x) for x in input().split()]


lst = []
i = 0
for num in str_in:
	if num != chess_set[i]:
			lst.append(chess_set[i] - num)
	else:
		lst.append(0)
	i += 1
print(" ".join(repr(n) for n in lst))