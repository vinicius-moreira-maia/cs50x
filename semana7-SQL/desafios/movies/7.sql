SELECT
   movies.title,
   ratings.rating
FROM
   ratings
JOIN
   movies
WHERE
   ratings.movie_id = movies.id
AND
   movies.year = 2010
AND
   ratings.rating > 0
ORDER BY
   ratings.rating DESC,
   movies.title;