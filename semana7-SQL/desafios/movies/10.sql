SELECT
   DISTINCT(people.name)
FROM
   people
JOIN
   directors
JOIN
   ratings
JOIN
   movies
WHERE
   directors.person_id = people.id
AND
   directors.movie_id = movies.id
AND
   ratings.movie_id = movies.id
AND
   ratings.rating >= 9.0;