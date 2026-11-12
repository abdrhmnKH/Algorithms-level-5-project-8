
# Queue Line (Ticketing) System (C++)

A small C++ console project that simulates a ticket queue like the ones used in banks and service centers. Each service has its own queue with its own ticket prefix and average serving time. The project is built around one class, `clsQueueLine`, which uses the STL `std::queue` (first in, first out) to store tickets.

This is project 8 of the Algorithms (Level 5) practice series.

## What It Does

- Creates several independent queues, each with a **prefix** (for example `A0`, `B0`) and an **average serving time** in minutes.
- Issues numbered tickets. The first ticket of the `A0` queue is `A01`, then `A02`, and so on.
- For every ticket it records the issue date and time, how many clients are waiting ahead, and the expected waiting time in minutes.
- Serves the next client in order (oldest ticket first).
- Prints the queue information and the tickets in different ways.

## The `clsQueueLine` Class

```cpp
clsQueueLine PayBillsQueue("A0", 10);   // prefix "A0", 10 minutes per client
```

| Method | Description |
|---|---|
| `clsQueueLine(prefix, serveMinutes)` | Creates a queue with a ticket prefix and an average serving time. |
| `IssueTicket()` | Adds a new ticket to the end of the queue. |
| `ServeNextClient()` | Serves the client at the front of the queue, removes their ticket, and prints the queue info. |
| `PrintInfo()` | Shows prefix, total tickets, served clients, and waiting clients. |
| `PrintTicketsLineRTL()` | Prints the ticket line with arrows pointing right to left: `A01 <-- A02 <-- A03` |
| `PrintTicketsLineLTR()` | Prints the ticket line with arrows pointing left to right: `A01 --> A02 --> A03` |
| `PrintAllTickets()` | Prints each ticket as a card: number, issue time, clients waiting ahead, and expected waiting time. |

Each ticket stores:

- `TicketNumber`: the prefix followed by the ticket count.
- `IssueTime`: the system date and time when the ticket was issued.
- `WaitingClients`: how many clients were already waiting when it was issued.
- `WaitingTime`: the expected waiting time in minutes, which equals the number of tickets before it multiplied by the average serving time.

For example, in a queue with a 10-minute average, the 3rd ticket has 2 clients ahead and an expected waiting time of 20 minutes.

## Demo (`main`)

The `main` function creates two queues and runs the same steps on each:

1. `PayBillsQueue` with prefix `A0` and 10 minutes per client. It issues 5 tickets.
2. `SubscriptionsQueue` with prefix `B0` and 5 minutes per client. It issues 3 tickets.
3. For each queue it prints the info, both ticket lines, and all ticket cards, then serves one client and prints the info again.

## Project Structure

```
Algorithms level 5 project 8.slnx
Algorithms level 5 project 8/
├── Algorithms level 5 project 8.cpp   # main(): demo of two queues
└── clsQueueLine.h                     # The queue line class
```

## Concepts Practiced

- Queue data structure (FIFO) with `std::queue`.
- Copying a queue to a temporary queue so it can be printed without changing the original.
- Classes with a nested class (`clsTickets`).
- Working with system date and time (`<ctime>`).

## Notes

- Tickets exist only in memory. Nothing is saved to a file when the program ends.
- The expected waiting time is calculated once, when the ticket is issued, and is not updated after a client is served.

## Author

[abdrhmnKH](https://github.com/abdrhmnKH)
