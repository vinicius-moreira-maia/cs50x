SELECT
   movies.title
FROM
   movies
JOIN
   people
JOIN
   stars
WHERE
   stars.person_id = people.id
AND
   stars.movie_id = movies.id
AND
   people.name = "Johnny Depp"

INTERSECT

SELECT
   movies.title
FROM
   movies
JOIN
   people
JOIN
   stars
WHERE
   stars.person_id = people.id
AND
   stars.movie_id = movies.id
AND
   people.name = "Helena Bonham Carter";