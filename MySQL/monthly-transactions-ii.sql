# Time:  O(n)
# Space: O(n)

select month, country,
    sum(IF( type = "approved", 1, 0)) as approved_count,
    sum(IF( type = "approved", amount, 0)) as approved_amount,
    sum(IF( type = "chargeback", 1, 0)) as chargeback_count,
    sum(IF( type = "chargeback", amount, 0)) as chargeback_amount
from (
    (
    select left(t.trans_date, 7) as month, t.country, amount,'approved' as type
    from Transactions as t
    where state='approved'
    ) 
    union all (
    select left(c.trans_date, 7) as month, t.country, amount,'chargeback' as type
    from Transactions as t inner join Chargebacks as c
    on t.id = c.trans_id
    )
) as tt
group by tt.month, tt.country
