# Time:  O(nlogn)
# Space: O(n)

# regular expression
SELECT *,
       dna_sequence REGEXP '^ATG' AS has_start,
       dna_sequence REGEXP 'TAA$|TAG$|TGA$' AS has_stop,
       dna_sequence REGEXP 'ATAT' AS has_atat,
       dna_sequence REGEXP 'GGG' AS has_ggg
FROM samples
ORDER BY sample_id;
