# Reservation_System

## Problem Statement
The company has several offices with computers (which can accommodate different numbers of people). Now a system needs to be developed so that employees can book places in advance to prevent overcrowding in the office.

![image](pics/empty-office-modern-clean.png)

## Requirements
1. Users:
- Employee:         Request for the positions
- System manager:   Create the account for the boss and employees
- Boss:             Check the request from the employees
2. Offices
- Office 1:         Up to 20 people
- Office 2:         Up to 50 people
- Office 3:         Up to 100 people
3. Reservation System:
- Log in page
  - Employee
  - System manager
  - Boss
  - Exit
- Verification
  - Employee:         E_ID, name and password
  - System manager:   S_ID, name and password
  - Boss:             B_ID, name and password
- Employee Menu
  - Make a reservation
  - Check my reservation
  - Check system reservation
  - Cancel the reservation
  - log out
- System Manager Menu
  - Add accounts
  - Check info of the users
  - Check all the reservation
  - Clear the history
  - log out
 - Boss Menu
  - Check all the reservation
  - Accept or reject the request
  - log out
4. Request Rules:
- Employee can request for the whole week.
- System manager must clear the request every week.
- Boss should check the request from the employee wo decide whether to accept or reject.

