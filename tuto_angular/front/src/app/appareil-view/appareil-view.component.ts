import { Component, OnInit } from '@angular/core';
import { AppareilService } from '../services/appareil.service';
import { Appareil } from '../models/appareil'
import { Subscription } from 'rxjs'

@Component({
  selector: 'app-appareil-view',
  templateUrl: './appareil-view.component.html',
  styleUrls: ['./appareil-view.component.scss']
})

export class AppareilViewComponent implements OnInit {
	isAuth = false;

	appareils: Appareil[];
	appareilSubscription: Subscription;


	lastUpdate = new Promise((resolve, reject) => {
	  const date = new Date();
	  setTimeout(
		() => {
		  resolve(date);
		}, 1000
	  );
	});
  
	constructor(private appareilService: AppareilService) { }
  
	ngOnInit() {
	  this.appareilSubscription = this.appareilService.appareilsSubject.subscribe(
		  (appareil: Appareil[]) => {
			  this.appareils = appareil;
		  }
	  );
	  this.appareilService.emitAppareilSubject();
	}
  
	onAllumer() {
	  this.appareilService.switchOnAll();
	}
  
	onEteindre() {
	  if(confirm('Etes-vous sûr de vouloir éteindre tous vos appareils ?')) {
		this.appareilService.switchOffAll();
	  } else {
		return null;
	  }
	}


	ngOnDestroy() {
		this.appareilSubscription.unsubscribe();
	}
}
