-- insert into teacher values('803','liao','man',null,'professor','computer');
-- insert into teacher values('801','lilao','man',null,'professor','computer');
-- insert into teacher values('802','lijun','man',null,'professor','computer');
-- insert into teacher values('811','lifan','man',null,'professor','computer');
-- insert into teacher values('804','lihoo','man',null,'professor','music');
-- insert into teacher values('805','lihao','man',null,'professor','sport');
-- insert into teacher values('806','lichen','man',null,'professor','english');
-- insert into teacher values('807','liyan','man',null,'professor','math');
-- insert into teacher values('808','chen','man',null,'professor','computer');


-- insert into course values('9-888','math','803');
-- insert into course values('9-128','english','801');
-- insert into course values('9-688','computer','802');
-- insert into course values('9-868','math','808');

insert into score values('104','9-688','90');
insert into score values('103','9-868','90');
insert into score values('102','9-128','92');
insert into score values('105','9-888','67');
insert into score values('106','9-688','70');
insert into score values('107','9-868','50');
insert into score values('108','9-128','82');

select degree from score where sno='103' and cno='9-868';
select *frome score where degree>(select degree from score where sno='103' and cno='9-868'
);