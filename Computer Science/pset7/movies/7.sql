select title, rating from movies join ratings on movies.id=ratings.movie_id where movies.year=2010 group by movies.title order by rating desc;
