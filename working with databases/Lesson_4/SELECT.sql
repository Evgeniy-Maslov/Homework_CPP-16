--Задание 2
--Написать SELECT-запросы, которые выведут информацию согласно инструкциям ниже.
--Внимание: результаты запросов не должны быть пустыми, учтите это при заполнении таблиц.

--1 Название и продолжительность самого длительного трека.
select name as Name_Tracks, duration 
from track
order by duration desc 
limit 1;

--2 Название треков, продолжительность которых не менее 3,5 минут.
select name as Name_Tracks
from track
where duration >= 3.5;

--3 Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
select name as name_collection
from collection
where year_release between 2018 and 2020;

--4 Исполнители, чьё имя состоит из одного слова.
select name as name_Singer
from singer
where name not like '% %';

--5 Название треков, которые содержат слова «мой» или «my».
select name as Name_Tracks
from track
where name like '% my %';

--Задание 3
--Написать SELECT-запросы, которые выведут информацию согласно инструкциям ниже.
--Внимание: результаты запросов не должны быть пустыми, при необходимости добавьте данные в таблицы.

--1 Количество исполнителей в каждом жанре.
select name, COUNT(singer_id) as count_singer
from genre left join genre_singer
on genre.genre_id = genre_singer.genre_id 
group by genre.genre_id
order by genre.genre_id;

--2 Количество треков, вошедших в альбомы 2019–2020 годов.
select albom.name as name_albom, year_release, COUNT(track_id) as count_track
from albom left join track
on albom.albom_id = track.albom_id 
where year_release between 2019 and 2020
group by albom.albom_id ;

--3 Средняя продолжительность треков по каждому альбому.
select albom.name as name_albom, avg(duration) as avg_duration
from albom left join track
on albom.albom_id = track.albom_id 
group by albom.name
order by avg_duration;

--4 Все исполнители, которые не выпустили альбомы в 2020 году.
select singer.name
from albom
join singer_albom on albom.albom_id = singer_albom.albom_id 
join singer on singer_albom.singer_id = singer.singer_id 
where singer.singer_id != (select singer.singer_id
						from singer
						join singer_albom on singer.singer_id = singer_albom.singer_id 
						join albom on singer_albom.albom_id = albom.albom_id 
						where albom.year_release = 2020)
group by singer.name;

--5 Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).
select collection.name as collection
from track
join collection_track on collection_track.track_id = track.track_id
join collection on collection.collection_id = collection_track.collection_id 
where track.track_id in (select track.track_id 
						from track
						join singer_albom on track.albom_id = singer_albom.albom_id 
						join singer on singer_albom.singer_id = singer.singer_id 
						where singer.name = 'Ray Charle')
order by collection.collection_id;

--Задание 4*
--Написать SELECT-запросы, которые выведут информацию согласно инструкциям ниже.
--Внимание: результаты запросов не должны быть пустыми, при необходимости добавьте данные в таблицы.

--1 Названия альбомов, в которых присутствуют исполнители более чем одного жанра.
select albom.name as name_albom
from albom 
join singer_albom on singer_albom.albom_id = albom.albom_id 
where singer_albom.singer_id in (select singer.singer_id 
					from singer
					join genre_singer on genre_singer.singer_id = singer.singer_id 
					group by singer.singer_id
					having count(*) > 1);

--2 Наименования треков, которые не входят в сборники.
select track.track_id as id, track.name as name_track
from track 
where track.track_id not in (select collection_track.track_id
						from collection_track)
order by id;					
						
--3 Исполнитель или исполнители, написавшие самый короткий по продолжительности трек, — теоретически таких треков может быть несколько.
select singer.name as name_singer
from singer_albom
join singer on singer.singer_id = singer_albom.singer_id 
where singer_albom.albom_id in (select track.albom_id 
								from track
								where track.duration = (select min(track.duration)
														from track));

--4 Названия альбомов, содержащих наименьшее количество треков.
select albom.name
from albom
where albom.albom_id in (select track.albom_id
						from track
						group by track.albom_id
						having count(track.track_id) =  (select count(track.track_id)
														from track
														group by track.albom_id
														order by count(track.track_id)
														limit 1))
