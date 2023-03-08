create  table teacher(
    tno varchar(20) primary key,
    tname varchar(20) not null,
    tsex varchar(20) not null,
    tbirthday datetime,
    prof varchar(20),
    depart varchar(20) not null
);

create table course(
    cno varchar(20) primary key,
    cname varchar(20) not null,
    tno varchar(20) not null,
    foreign  key(tno) references teacher(tno)
);