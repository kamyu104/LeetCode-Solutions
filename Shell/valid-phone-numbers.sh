#!/usr/bin/env bash
# Time:  O(n)
# Space: O(1)

grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

sed -n -E '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

