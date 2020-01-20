import { Component, OnInit } from '@angular/core';
import {Image} from '../models/image';
import { ModesService } from '../services/modes.service';
@Component({
  selector: 'app-central',
  templateUrl: './central.component.html',
  styleUrls: ['./central.component.scss']
})
export class CentralComponent implements OnInit {

  centralGradient: Image[] =
  [{col_id: 1, name: 'blue', src: '../../assets/images/central_gradient/1.png'},
   {col_id: 2, name: 'blue2', src: '../../assets/images/central_gradient/2.png'},
   {col_id: 3, name: 'green', src: '../../assets/images/central_gradient/3.png'},
   {col_id: 4, name: 'orange', src: '../../assets/images/central_gradient/4.png'},
   {col_id: 5, name: 'purple', src: '../../assets/images/central_gradient/5.png'},
   {col_id: 6, name: 'purple_red', src: '../../assets/images/central_gradient/6.png'},
   {col_id: 7, name: 'red_yellow', src: '../../assets/images/central_gradient/7.png'},
   {col_id: 8, name: 'yellow', src: '../../assets/images/central_gradient/8.png'},
   {col_id: 9, name: 'yellow_green', src: '../../assets/images/central_gradient/9.png'}
  ];
   constructor(private modeRepository: ModesService) { }

  ngOnInit() {
  }

  sendColor(color) {
    this.modeRepository.sendColor(color).subscribe();
  }
}
