import socket
import tkinter as tk
from tkinter import messagebox

HOST = "127.0.0.1"
PORT = 5000

def invia_dati():
    dati = text_area.get("1.0", tk.END).strip()

    if dati == "":
        messagebox.showerror("Errore", "Inserisci dei dati")
        return

    # Controllo formato
    righe = dati.split("\n")
    for riga in righe:
        parti = riga.split(";")
        if len(parti) != 3:
            messagebox.showerror("Errore", f"Formato errato:\n{riga}")
            return
        try:
            float(parti[1])
            float(parti[2])
        except ValueError:
            messagebox.showerror("Errore", f"Valori non numerici:\n{riga}")
            return

    try:
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.connect((HOST, PORT))
        client.sendall(dati.encode("utf-8"))

        risposta = client.recv(4096).decode("utf-8")
        client.close()

        messagebox.showinfo("Risultati", risposta)

    except:
        messagebox.showerror("Errore", "Server non raggiungibile")

# ===== GUI =====
root = tk.Tk()
root.title("Invio Temperature Giornaliere – Stazione Meteo")
root.geometry("520x400")

label = tk.Label(
    root,
    text="Inserisci i dati (una riga per giorno):\nGG/MM/AAAA;T12;T24"
)
label.pack(pady=10)

text_area = tk.Text(root, width=55, height=12)
text_area.pack(pady=10)

btn = tk.Button(root, text="Invia dati", command=invia_dati)
btn.pack(pady=10)

root.mainloop()