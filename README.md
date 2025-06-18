# 🏦 Banking Management System in C++

This project is a comprehensive **Banking Management System** implemented in **C++**,  
showcasing core principles of **Object-Oriented Programming (OOP)** and real-world application design.  
The system simulates the operations of a bank, including account creation, transactions, user roles,  
and account management with full encapsulation, inheritance, and polymorphism.

---

## 🚀 Features

### 🧾 Account Management
- Create **Savings** or **Current** accounts  
- Deposit / Withdraw funds  
- View account details  
- Close accounts  

### 👥 User Roles
- **Customer** : Manage their personal accounts  
- **Employee** : Access and manage all bank accounts  

### 🏦 Account Types
- **Savings Account** : 8% interest per annum  
- **Current Account** : Overdraft facility available  

### 🔒 Transaction Security
- Input validation for data integrity  
- Minimum balance enforcement  
- Overdraft protection (for current accounts)  

---

## 💡 OOP Concepts Demonstrated

### 🧊 Encapsulation
- Data hiding via private/protected members  
- Public member functions for secure access  

### 🧬 Inheritance
- `Savings_Account` and `Current_Account` derive from abstract base class `Account`  
- `Bank_Employee` and `Bank_Customer` derive from controller class `Bank_Operations`  

### 🎭 Polymorphism
- Use of **virtual functions** for runtime behavior  
- Common interface with account-specific behaviors  

### 📦 Abstraction
- Abstract base classes with pure virtual functions  
- Simplified interface hiding internal complexities  

### 🧹 Memory Management
- Dynamic memory with vectors of pointers  
- Proper destructors ensure no memory leaks  

---

## 🧱 Class Structure

├── Account (Abstract Base Class)
│   ├── Savings_Account (Savings Account Logic)
│   └── Current_Account (Current Account Logic)
│
├── Bank_Operations (Base class for banking operations)
│   ├── Bank_Employee (Employee operations access)
│   └── Bank_Customer (Customer operations access)
│
└── Bank (Main System Controller)

---

## 🔧 Usage Examples

### 👤 Customer 
1. Open a savings or current account  
2. Deposit funds  
3. Check balance and account details  
4. Withdraw funds  

### 🧑‍💼 Employee 
1. View all registered accounts  
2. Process customer withdrawals and deposits  
3. Close accounts  
4. Manage overdraft limits  

---

## 📂 File Structure

| File Name             | Description                               |
|---------------------- |-------------------------------------------|
| `Account.h`           | Base account class and abstract interface |
| `Savings_Account.h`   | Implementation of savings account         |
| `Current_Account.h`   | Current account with overdraft handling   |
| `Bank_Operations.h`   | Core banking operations                   |
| `Bank_Employee.h`     | Employee-specific logic and menu          |
| `Bank_Customer.h`     | Customer-specific operations              |
| `Bank.h`              | System controller for initialization      |
| `main.cpp`            | Entry point for the program               |

---

## 👨‍💻 Author

**Yash Kumar Singh**  
📘 DU PGDAV | 🖥️ Computer Science (Hons) | 💡 Web & Software Developer  
🔗 [LinkedIn](https://www.linkedin.com/in/yash-kumar-singh-)  
📬 [Email](mailto:yashkumarsingh1607@gmail.com)
