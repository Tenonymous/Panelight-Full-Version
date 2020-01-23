import { Component, OnInit } from '@angular/core';
import {Image} from '../models/image';
import { ModesService } from '../services/modes.service';

@Component({
  selector: 'app-vertical-two',
  templateUrl: './vertical-two.component.html',
  styleUrls: ['./vertical-two.component.scss']
})
export class VerticalTwoComponent implements OnInit {

  verticalStripes: Image[] =
  [{col_id: 1, name: 'amber_green', src: '../../assets/images/vertical_stripes2/1.png'},
   {col_id: 2, name: 'gold_magenta', src: '../../assets/images/vertical_stripes2/2.png'},
   {col_id: 3, name: 'ocean_amber', src: '../../assets/images/vertical_stripes2/3.png'},
   {col_id: 4, name: 'ocean_plum', src: '../../assets/images/vertical_stripes2/4.png'},
   {col_id: 5, name: 'red_gold', src: '../../assets/images/vertical_stripes2/5.png'},
   {col_id: 6, name: 'red_green', src: '../../assets/images/vertical_stripes2/6.png'},
  ];
  constructor(private modeRepository: ModesService) { }

  ngOnInit() {
  }

  sendColor(color) {
    this.modeRepository.sendColor(color).subscribe();
  }
}
