import { Component, OnInit, Input } from '@angular/core';

@Component({
  	selector: 'app-appareil',
  	templateUrl: './appareil.component.html',
  	styleUrls: ['./appareil.component.scss']
})

export class AppareilComponent implements OnInit {


	@Input() appareilName: string;
	@Input() appareilStatus: string;

	getColor() {
		if(this.appareilStatus === 'allumé') {
		  	return 'green';
		} 
		else if(this.appareilStatus === 'éteint') {
		  	return 'red';
		}
		else
			return 'black'
	}
  	constructor() { }

	getStatus() {
		return this.appareilStatus;
	  }
	
  	ngOnInit(): void {
  	}

}
