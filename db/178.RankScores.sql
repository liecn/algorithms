# Write your MySQL query statement below
Select
    Score,
    (SELECT count(*) FROM (SELECT DISTINCT Score s FROM Scores)tmp WHERE s>=Score) Rank
    FROM Scores
    order by Score desc;
