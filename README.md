# Managing a family's transactions
- A family needs an application to store all bank transactions for a month. 
- For each transaction, the day of the month in which it was carried out (between 1 and 28/29/30/31), the amount of money (positive integer), the type (tip-in = receive money/ tip-out = spend money) and transaction description are known. 
- The application respects the principle of layered architecture, has the following functionalities: CRUD operations, displaying a list of transactions that have a certain description and an amount greater than a given amount, displaying a list in descending order by the amount of money and filtering transactions by type-in/ tip-out and undo, i.e. the last operation is redone. Also, the app is tested but has no exceptions.
