# Life Simulator

Short Description 💬
-----------------
Console-based life simulation game implemented in C++. Players manage basic life stats such as health, hunger, energy, durability, age, and money. By working, eating, sleeping, and training at the gym, players try to survive and progress as long as possible. The project focuses on decision-based gameplay and stat management, demonstrating core C++ programming concepts.

Announcement 📢
------------
This project is written using C++17.

Features ✅
--------
- Menu-driven gameplay loop 🧭  
- Life statistics system (Health, Hunger, Energy, Durability) ❤️🍔⚡  
- Work system with income multiplier 💰  
- Age progression system ⏳  
- Simple life-death logic based on player conditions ☠️  
- Infinite gameplay loop until the player exits or dies ♾️  

### Example usage / sample session 💡

A short example flow (user input shown after prompts):

```text
=============================
Nickname: Alex
Age: 1
Cash: $1000
Income Multiplier: 1x
=============================
Health: %100
Hunger: %100
Energy: %100
Durability: %100
=============================
[1] - Work
[2] - Increase Income
[3] - Eat
[4] - Sleep
[5] - Gym
[6] - Exit
Choose: 1
// Player works, earns money, loses hunger, energy, and durability

Choose: 3
// Player eats and restores hunger

Choose: 6
// Program exits
```
### Notes and limitations ⚠️
- All progress is stored only in memory; exiting the program resets everything.  
- The game uses a simple stat-based logic for learning purposes.  
- No save/load system or advanced AI behavior.  
- Limited input validation; invalid input may cause unexpected behavior.  

### Author 👤
- wdemirkoll — GitHub: @wdemirkoll  
- 📅 January 2026

