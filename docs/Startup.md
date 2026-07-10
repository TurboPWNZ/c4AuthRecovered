Windows Loader
        │
        ▼
PE Entry Point
        │
        ▼
WinMainCRTStartup()   ← код CRT Microsoft
        │
        ├── _heap_init()
        ├── _mtinit()
        ├── _ioinit()
        ├── _setargv()
        ├── _setenvp()
        ├── _cinit()
        ▼
WinMain()             ← начало логики L2Auth
        │
        ├── FindWindow()
        ├── InitializeBlowfish()
        ├── DesKeyInit()
        ├── RegisterClassEx()
        ├── CreateWindowEx()
        ├── Config::Load()
        ├── DBEnv::Init()
        ├── CreateIOThread()
        ├── ListenThread()
        ▼
Message Loop
