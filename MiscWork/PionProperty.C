void PionProperty(){

  gROOT->SetStyle("Plain");
  
  TCanvas *c1 = new TCanvas();
  c1->SetGridx();
  c1->SetGridy();
  
  TF1 *f1 = new TF1("f1","x * 1./sqrt(1.-x*x)",0.06,1.000000);
  TF1 *f2 = new TF1("f2","x",0.06,1.000000);
  f2->SetLineStyle(2); 
  f2->SetLineColor(2); 

  f1->SetNpx(10000);
  
  f1->SetTitle("#beta vs #beta#gamma");
  f1->GetXaxis()->SetTitle("#beta");
  f1->GetYaxis()->SetTitle("#beta#gamma");
  f1->GetYaxis()->SetRangeUser(0.00001, 3);
  f1->Draw("C");
  f2->Draw("same");
  c1->Print("betagamma.ps");  
  

  f1->GetYaxis()->SetRangeUser(0.00001, 100000);
  gPad->SetLogx();
  gPad->SetLogy(); 
  
  
  

  f1->Draw("C");
  c1->Print("betagamma_log.ps");
  
  double mass_proton = 938.2;//MeV
  double kE;
  
  TF1 *f3 = new TF1("f3","938.2 * x * 1./sqrt(1.-x*x)",0.06,0.9);
  f3->SetNpx(10000);
  f3->SetTitle("#beta vs momentum  #scale[1.2]{#color[4]{   Proton}}");
  f3->GetXaxis()->SetTitle("#beta");
  f3->GetYaxis()->SetTitle("momentum [MeV/c]");
  f3->Draw("C");
  c1->Print("proton_mom.ps");  

  TF1 *f4 = new TF1("f4","139.57 * x * 1./sqrt(1.-x*x)",0.06,0.9);
  f4->SetNpx(10000);
  f4->SetTitle("#beta vs momentum  #scale[1.2]{#color[2]{   Pion}}");
  f4->GetXaxis()->SetTitle("#beta");
  f4->GetYaxis()->SetTitle("momentum [MeV/c]");
  f4->Draw("C");
  c1->Print("pion_mom.ps");  

  
  TF1 *f5 = new TF1("f5","139.57 *( sqrt(x * x *1./(1.-x*x) + 1.) -1. )",0.06,0.9);
  f5->SetNpx(10000);
  f5->SetTitle("#beta vs kinetic Energy  #scale[1.2]{#color[2]{   Pion}}");
  f5->GetXaxis()->SetTitle("#beta");
  f5->GetYaxis()->SetTitle("kinetic Energy [MeV]");
  f5->Draw("C");
  c1->Print("pion_kE.ps");  

  
  TF1 *f6 = new TF1("f6","938.2 *( sqrt(x * x *1./(1.-x*x) + 1.) -1. )",0.06,0.9);
  f6->SetNpx(10000);
  f6->SetTitle("#beta vs kinetic Energy  #scale[1.2]{#color[4]{   Proton}}");
  f6->GetXaxis()->SetTitle("#beta");
  f6->GetYaxis()->SetTitle("kinetic Energy [MeV]");
  f6->Draw("C");
  c1->Print("proton_kE.ps");  


  TF1 *f7 = new TF1("f7","sqrt(x * x + 938.2* 938.2) -938.2 ",30,1001.);
  f7->SetNpx(10000);
  f7->SetTitle("momentum vs kinetic Energy  #scale[1.2]{#color[4]{   Proton}}");
  f7->GetXaxis()->SetTitle("momentum [MeV/c]");
  f7->GetYaxis()->SetTitle("kinetic Energy [MeV]");
  f7->Draw("C");
  c1->Print("proton_mom_kE.ps");  

  TF1 *f8 = new TF1("f8","sqrt(x * x + 139.57* 139.57) -139.57 ",30,1001.);
  f8->SetNpx(10000);
  f8->SetTitle("momentum vs kinetic Energy  #scale[1.2]{#color[2]{   Pion}}");
  f8->GetXaxis()->SetTitle("momentum [MeV/c]");
  f8->GetYaxis()->SetTitle("kinetic Energy [MeV]");
  f8->Draw("C");
  c1->Print("pion_mom_kE.ps");  
  
}
