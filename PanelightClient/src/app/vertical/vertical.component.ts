import { Component, OnInit } from '@angular/core';
import {Image} from '../models/image';
import { ModesService } from '../services/modes.service';

@Component({
  selector: 'app-vertical',
  templateUrl: './vertical.component.html',
  styleUrls: ['./vertical.component.scss']
})
export class VerticalComponent implements OnInit {

  verticalStripes: Image[] =
  [{col_id: 1, name: 'amber', src: '../../assets/images/vertical_stripes/1.png'},
   {col_id: 2, name: 'gold', src: '../../assets/images/vertical_stripes/2.png'},
   {col_id: 3, name: 'green', src: '../../assets/images/vertical_stripes/3.png'},
   {col_id: 4, name: 'magenta', src: '../../assets/images/vertical_stripes/4.png'},
   {col_id: 5, name: 'ocean', src: '../../assets/images/vertical_stripes/5.png'},
   {col_id: 6, name: 'plum', src: '../../assets/images/vertical_stripes/6.png'},
  ];
  constructor(private modeRepository: ModesService) { }

  ngOnInit() {
  }

  sendColor(color) {
    this.modeRepository.sendColor(color).subscribe();
  }
}
