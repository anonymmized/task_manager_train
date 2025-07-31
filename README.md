# 📝 To-Do List Manager (C++ Console App)

A simple, terminal-based To-Do List Manager written in C++. This project helps you practice basic C++ concepts like structs, vectors, file handling, user input, and terminal colors. It's a beginner-friendly project designed to strengthen your foundational skills.

---

## 🚀 Features

- ✅ Add new tasks
- 📋 View all tasks with color-coded status
- 🟢 Mark tasks as completed
- 🗑️ Delete tasks
- ✏️ Edit existing tasks
- 🗂️ Assign categories/tags to tasks
- 💾 Save tasks to a file (`tasks.txt`)
- 📂 Load tasks on startup
- 🔍 Filter tasks by category *(optional)*

---

## 🛠️ Technologies Used

- C++ (Standard Library)
- Console I/O (`cin`, `cout`)
- File handling with `<fstream>`
- ANSI escape codes for terminal colors

---

## 📦 How to Compile

Using `g++` (or any C++ compiler):

```bash
g++ -std=c++11 -o todo todo.cpp
./todo
```

> Make sure your terminal supports ANSI colors.

---

## 🗃️ File Format

Tasks are saved in a simple CSV-like format in `tasks.txt`:

```
Task description,completed,category
```

Example:

```
Buy groceries,Pending,Home
Finish project,Complete,Work
```

---

## 🧠 Educational Goals

This project helps reinforce:

* Working with structs and vectors
* File input/output
* Basic string manipulation
* Console UI in C++
* Error handling and input validation

---

## 📌 To-Do / Possible Extensions

* Add due dates or deadlines
* Add task priority levels
* Sort tasks by status or priority
* Password protection for file access
* Export/import as CSV
* Graphical UI (using a library like ncurses)

---

## 👤 Author

Developed by **[@anonymmized](https://github.com/anonymmized)**
Feel free to fork, contribute, or leave feedback!