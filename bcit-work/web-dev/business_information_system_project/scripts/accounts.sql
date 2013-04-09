DROP TABLE IF EXISTS accounts;
CREATE TABLE accounts 
(
`id` varchar(3) NOT NULL,
`accountname` varchar(80),
`status` varchar(1),
	PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO accounts(id, accountname, status) 
	VALUES ('001', 'Assets', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('002', 'Liabilities', 'D');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('003', 'Equity', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('004', 'Expenses', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('005', 'Cash', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('006', 'Mortgages', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('007', 'Loans', 'D');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('008', 'Common Stock', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('009', 'Services', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('010', 'Wages', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('011', 'Payroll', 'A');
INSERT INTO accounts(id, accountname, status) 
	VALUES ('012', 'PP&E', 'A');