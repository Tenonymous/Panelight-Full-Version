package main 

import (
	"fmt"
	"encoding/json"
	"net/http"
)

type Mode struct {
	Id int `json:"Id"`
}

type Color struct {
	Name string `json:"Name"`
}

type Option struct {
	Id int `json:"Id"`
	Color string `json:"Color"`
}

func setupCORS(w *http.ResponseWriter, req *http.Request) {
    (*w).Header().Set("Access-Control-Allow-Origin", "*")
    (*w).Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
    (*w).Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")
}

var mode Mode
var color Color 
var option Option
func jsonHandler(w http.ResponseWriter, r *http.Request) {
	setupCORS(&w, r)
    if (*r).Method == "OPTIONS" {
        return
    }
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(option);
}

func parseModeHandler(rw http.ResponseWriter, request *http.Request) {
	setupCORS(&rw, request)
    if (*request).Method == "OPTIONS" {
        return
    }
	decoder := json.NewDecoder(request.Body)

	err := decoder.Decode(&mode)

	if err != nil {
		panic(err)
	}
	option.Id = mode.Id

	fmt.Println(mode.Id)
}

func parseColorHandler(rw http.ResponseWriter, request *http.Request) {
	setupCORS(&rw, request)
    if (*request).Method == "OPTIONS" {
        return
    }
	decoder := json.NewDecoder(request.Body)

	err := decoder.Decode(&color)

	if err != nil {
		panic(err)
	}
	option.Color = color.Name
	fmt.Println(color.Name)
}
func main() {
	http.HandleFunc("/mode", parseModeHandler)
	http.HandleFunc("/color", parseColorHandler)
	http.HandleFunc("/json", jsonHandler)
	http.ListenAndServe(":8081", nil)
}
