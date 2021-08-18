import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
	isAuth = false;

	appareils = [
		{
		  name: 'Machine à laver',
		  status: 'off'
		},
		{
		  name: 'Frigo',
		  status: 'on'
		},
		{
		  name: 'Ordinateur',
		  status: 'off'
		}
	  ];
	
	constructor() {
		setTimeout(
			() => {
				this.isAuth = true;
			}, 2000
		);
	}

	onAllumer() {
		console.log('On allume tout !');
	}
}
