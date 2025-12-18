import socket

HOST = "127.0.0.1"   # localhost
PORT = 5000          # porta del server

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print(f"Server in ascolto su {HOST}:{PORT}")

conn, addr = server.accept()
print("Client connesso:", addr)

data = conn.recv(4096).decode("utf-8")

righe = data.strip().split("\n")

temperature = []
giorni = 0

for riga in righe:
    try:
        data_giorno, t12, t24 = riga.split(";")
        t12 = float(t12)
        t24 = float(t24)

        temperature.append(t12)
        temperature.append(t24)
        giorni += 1
    except:
        pass   # ignora righe non valide

if temperature:
    media = sum(temperature) / len(temperature)
    massimo = max(temperature)
    minimo = min(temperature)

    risposta = (
        f"Numero giorni analizzati: {giorni}\n"
        f"Numero rilevazioni totali: {len(temperature)}\n\n"
        f"Temperatura media: {media:.2f} °C\n"
        f"Temperatura massima: {massimo} °C\n"
        f"Temperatura minima: {minimo} °C\n"
    )
else:
    risposta = "Nessun dato valido ricevuto."

conn.sendall(risposta.encode("utf-8"))

conn.close()
server.close()
print("Connessione chiusa")