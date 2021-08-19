import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { FormsModule } from '@angular/forms';
import { AppareilComponent } from './appareil/appareil.component';
import { AppareilService } from './services/appareil.service';
import { AuthService } from './services/auth.service';
import { AuthComponent } from './auth/auth.component';
import { AppareilViewComponent } from './appareil-view/appareil-view.component';
import { SingleAppareilComponent } from './single-appareil/single-appareil.component';
import { FourOhFourComponent } from './four-oh-four/four-oh-four.component';
import { AuthGuard } from './services/auth-guard.service';

@NgModule({
	declarations: [
    	AppComponent,
    	AppareilComponent,
    	AuthComponent,
    	AppareilViewComponent,
	 SingleAppareilComponent,
	 FourOhFourComponent
	],
	
	imports: [
    	BrowserModule,
		AppRoutingModule,
		FormsModule
  	],
  	providers: [
		AppareilService,
		AuthService,
		AuthGuard,
  ],
  bootstrap: [AppComponent]
})

export class AppModule { 
}