SELECT
   people.name
FROM
   movies
JOIN
   people
JOIN
   stars
WHERE
NOT
   (people.name = "Kevin Bacon" AND people.birth = 1958)
AND
   stars.person_id = people.id
AND
   stars.movie_id = movies.id
AND
   movies.id

IN (

SELECT
   movies.id
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
   people.name = "Kevin Bacon"
AND
   people.birth = 1958

);