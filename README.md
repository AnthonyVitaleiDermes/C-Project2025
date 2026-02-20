# 🛒 C++ Store & Minigame Project
<img width="835" height="442" alt="ShopSimMainScreen" src="https://github.com/user-attachments/assets/ee7eca85-6f89-40c8-8956-d53620c73c07" />


A console-based C++ application featuring an interactive shop system and a Rock-Paper-Scissors minigame. Built with object-oriented and generic programming principles including templates, tree structures, and stacks.

---

## Features

- **Shop System** — Browse a hierarchical store menu organized by category, purchase items, and track your purchase history
- **Rock-Paper-Scissors Minigame** — Play against "Lana" to earn or lose money
- **Inventory System** — Track owned items with quantity management
- **Purchase History** — View past purchases stored in a stack

---

## Project Structure

```
C++Project/
├── C++Project.cpp      # Entry point / main loop
├── shop.h              # Shop class with tree-based menu structure
├── StoreItem.h         # Generic StoreItem<IDType, PriceType> template class
├── Inventory.h         # Generic Inventory<IDType, PriceType> template class
├── Money.h / .cpp      # Money class for managing balances
├── Game.h / Game.cpp   # RPSGame class (Rock-Paper-Scissors logic)
└── ShopTemplate.h      # (Reserved for shop templates)
```

---

## How It Works

### Main Menu
On launch, the player enters their name and starts with **$100.00**. They are then presented with three options:

| Option | Action |
|--------|--------|
| `1` | Open the Shop |
| `2` | Play the Minigame |
| `3` | View Purchase History |
| `0` | Exit |

---

### 🏪 Shop
The shop is organized as a **tree structure** with nested categories:

```
Shop
├── Clothes
│   ├── Shirts
│   │   ├── T-Shirt       ($25.00)
│   │   └── Dress Shirt   ($40.00)
│   └── Pants
│       ├── Jeans          ($50.00)
│       └── Jorts          ($45.00)
├── Food
│   ├── Fruits
│   │   ├── Orange         ($2.50)
│   │   └── Lemon          ($1.80)
│   └── Berries
│       ├── Strawberry     ($3.00)
│       └── Blueberry      ($4.50)
└── Games
    └── Console
        ├── Xbox
        │   └── Xbox One
        │       ├── Halo   ($60.00)
        │       └── Forza  ($55.00)
        └── PlayStation
            └── PS5
                ├── Spider-Man   ($65.00)
                └── God of War   ($70.00)
```

- Items are **removed from the shop after purchase** (one-time buy)
- Insufficient funds will prevent a purchase

### 🎮 Minigame (Rock-Paper-Scissors)
Play against Lana with real monetary stakes:

| Result | Effect |
|--------|--------|
| Win    | +$20   |
| Lose   | -$10   |
| Draw   | $0     |

Earnings from the minigame are applied to your main balance when you exit.

### 📦 Inventory & Purchase History
- The **Inventory** class uses a linked list to track items and quantities
- The **Purchase History** is stored as a stack (LIFO), viewable from the main menu

---

## Key Classes

### `StoreItem<IDType, PriceType>`
A generic template class representing a purchasable item with an ID, name, price, and quantity.

### `Shop<IDType, PriceType>`
Manages a tree of `ShopNode` objects representing categories and items. Supports display, purchase, and history tracking via a `std::stack`.

### `Inventory<IDType, PriceType>`
A generic inventory container backed by `std::list`, supporting add, remove, and lookup operations.

### `Money`
Simple wrapper around a `float` balance with display and mutation methods.

### `RPSGame`
Encapsulates Rock-Paper-Scissors logic, tracking earnings independently via an internal `Money` object.

---

## Building the Project

This project was built with **Visual Studio 2022** targeting Windows (x64/x86).

1. Open `C++Project.sln` in Visual Studio
2. Select your desired configuration (`Debug` or `Release`) and platform (`x64` or `x86`)
3. Build and run with **Ctrl+F5**

> Requires: Visual Studio 2019+ with the **Desktop development with C++** workload installed.

---

## Notes

- The minigame tracks its own balance independently and only syncs to the main wallet on exit
- Purchased shop items cannot be rebought in the same session
- The player starts each session with **$100.00**
