# 🏏 Cricket Team Management System

A C++ command-line application designed for cricket team management to analyze and manage player records, performance statistics, financial calculations (salary, bonuses, fines), and squad selection.

---

## 👥 Targeted Users
- **Chairperson** (Strategic oversight & payroll review)
- **Manager** (Administrative details & file persistence)
- **Coaches** (Performance tracking, ranking & player selection)

---

## 📌 Functional Features
- **Authentication:** Secure login module for system access.
- **Player & Stat Management:** Add basic player profiles and performance metrics (runs, wickets, matches).
- **Financial Calculations:** Dynamic calculation of salaries, bonuses, and performance fines.
- **Rankings & Selection:** Rank players based on batting averages/bowling economy and select top performers.
- **Data Persistence:** Export player records and statistical data to external files (`players.txt`).
- **Match Schedules:** Built-in view for upcoming team match schedules.

---

## 🛠️ Data Structures & Technical Specs

The application manages data using parallel arrays across key player attributes:

| Variable | Data Type | Description |
| :--- | :--- | :--- |
| `name[]` / `surname[]` | `string` | Player first and last names |
| `age[]` | `int` | Player age |
| `match[]` | `int` | Total matches played |
| `run[]` | `int` | Total runs scored |
| `wicket[]` | `int` | Total wickets taken |
| `salary[]` | `int` | Assigned base salary |
| `avg[]` | `float` | Batting average |
| `eco[]` | `float` | Bowling economy rate |
| `bonus[]` / `fine[]` | `float` | Calculated bonus and penalty amounts |

### Core Function Prototypes
- `login()` — Authenticates user credentials.
- `showMenu()` — Displays main CLI navigation options.
- `inputPlayer()` & `inputPerformance()` — Captures profile and match statistics.
- `viewPlayers()` & `showRankings()` — Displays player details and ranked shortlists.
- `calculateBonus()` & `calculateFine()` — Evaluates financial adjustments.
- `saveToFile()` — Writes current memory state to file storage.
- `selection()` — Filters qualified players for match squads.

---

## ⚠️ Current Limitations & Code Insights
- **Sorting Efficiency:** Uses Bubble Sort for ranking logic, which can be optimized for larger datasets.
- **Data Loading:** Currently supports saving data to `players.txt`; auto-loading on startup is a planned enhancement.
- **Role Access:** Single-role access control; multi-user permissions (Admin vs. Coach vs. Manager) are in development.

---

## 🚀 Future Roadmap & Enhancements
- [ ] Implement search, filter, edit, and delete functionality for player records.
- [ ] Support format-specific analytics (ODI, T20, and Test matches).
- [ ] Add explicit roles/conditions for All-Rounders, Captains, and Vice-Captains.
- [ ] Enhance UI readability and implement bidirectional file I/O (File Read on startup).
- [ ] Add graphical team performance analytics.

---

## 💻 How to Run Locally

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/NoorulHudaImran209/Cricket-Team-Management-System.git](https://github.com/NoorulHudaImran209/Cricket-Team-Management-System.git)
