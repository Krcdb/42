import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { AuthComponent } from './auth/auth.component';
import { AppareilViewComponent } from './appareil-view/appareil-view.component';
import { SingleAppareilComponent } from './single-appareil/single-appareil.component';
import { FourOhFourComponent } from './four-oh-four/four-oh-four.component';
import { AuthGuard } from './services/auth-guard.service';

const appRoutes: Routes = [
	{ path: 'appareils', component: AppareilViewComponent, canActivate: [AuthGuard] },
	{ path: 'appareils/:id', component: SingleAppareilComponent, canActivate: [AuthGuard] },
	{ path: 'auth', component: AuthComponent },
	{ path: '', component: AppareilViewComponent },
	{ path: 'not-found', component: FourOhFourComponent },
	{ path: '**', redirectTo: 'not-found' }
];

@NgModule({
  imports: [RouterModule.forRoot(appRoutes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
