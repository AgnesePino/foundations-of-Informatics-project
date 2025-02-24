# Vaccination Scheduling Program

## Project Overview

This project is a vaccination scheduling platform designed for booking COVID-19 vaccination appointments at the "CV 19 Ex Gasometro Messina" site. The platform provides a user-friendly interface with a menu offering several options, including:

- Booking a new vaccination appointment
- Admin registration
- Admin login
- Exit

The program handles bookings based on user priorities, such as health conditions and professions, to allocate earlier dates when applicable.

---

## Features

### For Patients:
- Book a new vaccination appointment by providing:
  - Full name
  - Tax code
  - Age
  - Postal code (CAP)
  - Select profession and/or health conditions from predefined lists
- Priority assignment for users with listed professions or health conditions
- Automatic date assignment for vaccination if available
- Error handling for unavailable slots or duplicate registrations
- Exit the program at any time

### For Admin Personnel:
- Admin registration and login functionalities
- Modify the list of available professions and health conditions
- Add available vaccination slots
- View the list of all bookings made
- Manage the scheduling process based on user priority

---

## Technical Details

### Data Structures

- **User (utente.h)**: Linked list storing admin email and password. Users can only be added, not removed.

- **Booking (pren.h)**: Linked list storing patient details, including pointers to associated slots, professions, and health conditions. New nodes can only be added.

- **Professions (lavori.h)**: Linked list allowing addition and deletion of profession nodes.

- **Health Conditions (patologie.h)**: Linked list allowing addition and deletion of health condition nodes.

- **Slots (posti.h)**: Linked list representing available appointment slots. Slots can be added or removed, and each slot has an occupancy indicator.

- **Menu (menu.h)**: Provides functions for organized menu navigation within the main program.

---

## Main Operations

### User Operations (utente.h)
- **create_user()**: Initializes an empty user list.
- **register_user()**: Adds a new admin user after checking for duplicates.
- **login_user()**: Checks admin credentials for login purposes.
- **delete_users()**: Deletes all user nodes from memory.
- **load_users()**: Loads user data from the "Utenti" file.
- **save_users()**: Saves user data to the "Utenti" file.

### Booking Operations (pren.h)
- **create_booking()**: Initializes an empty booking list.
- **insert_booking()**: Adds a new booking after validating data and slot availability.
- **find_booking_by_tax_code()**: Searches for bookings by tax code.
- **display_booking()**: Shows details of a specific booking.
- **display_all_bookings()**: Lists all bookings.
- **delete_bookings()**: Removes all bookings from memory.
- **load_bookings()**: Loads booking data from the "Prenotazioni" file.
- **save_bookings()**: Saves booking data to the "Prenotazioni" file.

### Profession Operations (lavori.h)
- **create_profession_list()**: Initializes an empty profession list.
- **add_profession()**: Adds a new profession with automatic reordering.
- **delete_profession()**: Deletes a specified profession.
- **display_professions()**: Lists all professions.
- **load_professions()**: Loads profession data from the "Lavori" file.
- **save_professions()**: Saves profession data to the "Lavori" file.

### Health Condition Operations (patologie.h)
- **create_condition_list()**: Initializes an empty health condition list.
- **add_condition()**: Adds a new health condition.
- **delete_condition()**: Deletes a specified health condition.
- **display_conditions()**: Lists all health conditions.
- **load_conditions()**: Loads data from the "Patologie" file.
- **save_conditions()**: Saves data to the "Patologie" file.

### Slot Operations (posti.h)
- **create_slot_list()**: Initializes an empty slot list.
- **add_slot()**: Adds new slots in chronological order.
- **delete_slot()**: Deletes a slot if unoccupied.
- **display_slots()**: Shows available appointment slots.
- **load_slots()**: Loads slot data from the "Posti" file.
- **save_slots()**: Saves slot data to the "Posti" file.

### Menu Operations (menu.c)
- **menu_booking()**: Handles the booking process, including data validation and slot allocation.
- **menu_admin()**: Manages admin functions, such as adding/removing slots, professions, and conditions.
- **menu_registration()**: Handles admin user registration.

---

## Program Flow (main.c)

The main program flow:
1. Initialize all lists (users, bookings, professions, conditions, slots).
2. Load existing data from respective files.
3. Display the main menu:
   - **Book a Vaccination**: Redirects to `menu_booking()`
   - **Register as Admin**: Redirects to `menu_registration()`
   - **Admin Login**: Redirects to `menu_admin()`
   - **Exit**: Terminates the program
4. Before exiting, save all data back to files and deallocate memory.

---

## How to Run the Program

1. Compile the C source files using a suitable C compiler:
   ```bash
   gcc main.c menu.c utente.c pren.c lavori.c patologie.c posti.c -o vaccine_scheduler
   ```

2. Run the executable:
   ```bash
   ./vaccine_scheduler
   ```

---

## Conclusion

This vaccination scheduling platform ensures a streamlined process for both patients and medical personnel. It dynamically manages user bookings, prioritizes patients with health conditions or specific professions, and allows administrators to handle appointment slots and user data efficiently.

---

*Project developed by Agnese Concetta Pino*

