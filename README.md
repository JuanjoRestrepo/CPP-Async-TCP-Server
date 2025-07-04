# CPP-Async-TCP-Server
A minimalist, multithreaded asynchronous TCP server implemented in modern C++ using Boost.Asio. Designed as a learning and showcase project to demonstrate
socket programming, event-driven design, thread pooling, and modular architecture.

Well‑suited for inclusion in portfolios showcasing systems programming, backend development, and network engineering skills.


## 📂 Estructura del proyecto

cpp-async-tcp-server/
├── src/ # Código fuente del servidor
├── include/ # Cabeceras
├── scripts/ # Scripts de compilación/ejecución
├── tests/ # Pruebas unitarias (opcional)
├── Makefile # Reglas para compilar, ejecutar y limpiar
├── .gitignore # Archivos y carpetas ignoradas por Git
├── LICENSE # Licencia MIT
└── README.md # Documentación del proyecto

## 🚀 Installation & Usage

1. **Clone the repo**  
```bash
git clone https://github.com/YOUR_USERNAME/cpp-async-tcp-server.git
cd cpp-async-tcp-server
```

2. Build the project
```bash
  make
```

3. Run the server

```bash
./programa
```

4. Clean build artifacts

```bash
make clean
```

You can also use the build script to compile and run in one go:

```bash
./scripts/build.sh
```

🛠️ Technologies & Dependencies
- C++17 for modern language features
- Boost.Asio for asynchronous networking
- std::thread for multithreaded concurrency


