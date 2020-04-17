package main

import (
    "fmt"
    "net/http"
    "github.com/stackimpact/stackimpact-go"
)

func main() {
    agent := stackimpact.Start(stackimpact.Options{
        AgentKey: "a0bfdb9f36be5e383045a1bd8a3f7c9c7d5097f0",
        AppName: "Hello_World",
        AppVersion: "1.0.0",
        AppEnvironment: "Development",
    })

    agent.StartCPUProfiler();
    http.HandleFunc("/", HelloServer)
    http.ListenAndServe(":9000", nil)
    agent.ReportAllocationProfile();
    agent.StopCPUProfiler();
}

func HelloServer(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "Hello, %s!", r.URL.Path[1:])
}
