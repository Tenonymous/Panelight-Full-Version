import { Component, OnInit } from '@angular/core';
import {Image} from '../models/image';
import { ModesService } from '../services/modes.service';

@Component({
  selector: 'app-increasing',
  templateUrl: './increasing.component.html',
  styleUrls: ['./increasing.component.scss']
})
export class IncreasingComponent implements OnInit {

  increasingGradient: Image[] =
  [{col_id: 1, name: 'blue_dark', src: '../../assets/images/increasing_gradient/1.png'},
   {col_id: 2, name: 'blue_green', src: '../../assets/images/increasing_gradient/2.png'},
   {col_id: 3, name: 'green_violet', src: '../../assets/images/increasing_gradient/3.png'},
   {col_id: 4, name: 'green_orange', src: '../../assets/images/increasing_gradient/4.png'},
   {col_id: 5, name: 'green_red', src: '../../assets/images/increasing_gradient/5.png'},
   {col_id: 6, name: 'orange_red', src: '../../assets/images/increasing_gradient/6.png'},
   {col_id: 7, name: 'pink_darkblue', src: '../../assets/images/increasing_gradient/7.png'},
   {col_id: 8, name: 'pink_red', src: '../../assets/images/increasing_gradient/8.png'},
   {col_id: 9, name: 'yellow_blue', src: '../../assets/images/increasing_gradient/9.png'}
  ];

  constructor(private modeRepository: ModesService) { }

  ngOnInit() {
  }

  sendColor(color) {
    this.modeRepository.sendColor(color).subscribe();
  }
}
