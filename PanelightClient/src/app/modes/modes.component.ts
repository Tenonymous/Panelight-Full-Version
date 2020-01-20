import { Component, OnInit, Output, EventEmitter } from '@angular/core';
import {Mode} from '../models/image';
import { ModesService } from '../services/modes.service';

@Component({
  selector: 'app-modes',
  templateUrl: './modes.component.html',
  styleUrls: ['./modes.component.scss']
})
export class ModesComponent implements OnInit {

  modes: Mode[] =
  [{mode: 1, name: 'awakening', src: '../../assets/images/mode/1.png', href: ''},
   {mode: 2, name: 'sleeping', src: '../../assets/images/mode/2.png',  href: ''},
   {mode: 3, name: 'central gradient', src: '../../assets/images/mode/3.png',  href: '/central_gradient'},
   {mode: 4, name: 'increasing gradient', src: '../../assets/images/mode/4.png',  href: '/increasing_gradient'},
   {mode: 5, name: 'vertical stripes', src: '../../assets/images/mode/5.png',  href: '/vertical_stripes'},
   {mode: 6, name: 'vertical stripes 2', src: '../../assets/images/mode/6.png',  href: '/vertical_stripes2'}
  ];

  @Output() mode = new EventEmitter<string>();
  constructor(private modeRepository: ModesService) { }

  ngOnInit() {
  }
  sendMode(mode) {
    this.modeRepository.sendMode(mode).subscribe((res) => {
    });
  }
}
