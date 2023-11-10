SELECT
   movies.title
FROM
   movies
JOIN
   people
JOIN
   ratings
JOIN
   stars
WHERE
   stars.person_id = people.id
AND
   stars.movie_id = movies.id
AND
   movies.id = ratings.movie_id
AND
   people.name = "Chadwick Boseman"
ORDER BY
   ratings.rating DESC
LIMIT
   5;

