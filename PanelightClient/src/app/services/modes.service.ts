import { Injectable} from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class ModesService {

  private modeUrl = `http://localhost:8081/mode`;
  private colorUrl = `http://localhost:8081/color`;

  constructor(private http: HttpClient) {}

  sendMode(mode) {
    return this.http.post(this.modeUrl, {Id: mode});
  }

  sendColor(color) {
    return this.http.post(this.colorUrl, {Name: color});
  }

}
