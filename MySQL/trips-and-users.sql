# Time:  O((t * u) + tlogt)
# Space: O(t)

select 
t.Request_at Day, 
round(sum(case when t.Status = 'completed' then 0 else 1 end) / count(*), 2) Rate
from Trips t
inner join Users u 
on t.Client_Id = u.Users_Id and u.Banned = 'No'
where t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at

