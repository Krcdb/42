import { Component, OnInit } from '@angular/core';

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
		status: 'éteint'
	  },
	  {
		name: 'Frigo',
		status: 'allumé'
	  },
	  {
		name: 'Ordinateur',
		status: 'éteint'
	  }
	];

	constructor() {
		setTimeout(
		  () => {
			this.isAuth = true;
		  }, 1000
		);
	  }

	onAllumer() {
		console.log('On allume tout !');
	}

	ngOnInit(): void {
	}
}
