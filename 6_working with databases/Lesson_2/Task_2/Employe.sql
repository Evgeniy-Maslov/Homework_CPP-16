create table if not exists Employe(
	Employe_Id serial primary key,
	name varchar(20) not null,
	department varchar(50) not null,
	Boss_Id integer references Employe(Employe_Id) ON DELETE SET NULL
);