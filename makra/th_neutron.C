{
//=========Macro generated from canvas: c1/c1
//=========  (Wed May  9 02:37:25 2018) by ROOT version5.34/36
   TCanvas *c1 = new TCanvas("c1", "c1",2363,154,700,500);
   c1->Range(-22.25,-5199.338,200.25,46794.04);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp = new TH1F("htemp","col7 {col1==1}",100,0,178);
   htemp->SetBinContent(8,128);
   htemp->SetBinContent(9,614);
   htemp->SetBinContent(10,1227);
   htemp->SetBinContent(11,1848);
   htemp->SetBinContent(12,2639);
   htemp->SetBinContent(13,3378);
   htemp->SetBinContent(14,4284);
   htemp->SetBinContent(15,5121);
   htemp->SetBinContent(16,6014);
   htemp->SetBinContent(17,6548);
   htemp->SetBinContent(18,7238);
   htemp->SetBinContent(19,7768);
   htemp->SetBinContent(20,8104);
   htemp->SetBinContent(21,8436);
   htemp->SetBinContent(22,8437);
   htemp->SetBinContent(23,8391);
   htemp->SetBinContent(24,8512);
   htemp->SetBinContent(25,8320);
   htemp->SetBinContent(26,7986);
   htemp->SetBinContent(27,7811);
   htemp->SetBinContent(28,7710);
   htemp->SetBinContent(29,7267);
   htemp->SetBinContent(30,7081);
   htemp->SetBinContent(31,6797);
   htemp->SetBinContent(32,6663);
   htemp->SetBinContent(33,6504);
   htemp->SetBinContent(34,6292);
   htemp->SetBinContent(35,6262);
   htemp->SetBinContent(36,6001);
   htemp->SetBinContent(37,5908);
   htemp->SetBinContent(38,5931);
   htemp->SetBinContent(39,5849);
   htemp->SetBinContent(40,5878);
   htemp->SetBinContent(41,5904);
   htemp->SetBinContent(42,5971);
   htemp->SetBinContent(43,6831);
   htemp->SetBinContent(44,7953);
   htemp->SetBinContent(45,8832);
   htemp->SetBinContent(46,10351);
   htemp->SetBinContent(47,11654);
   htemp->SetBinContent(48,13008);
   htemp->SetBinContent(49,14573);
   htemp->SetBinContent(50,16419);
   htemp->SetBinContent(51,18233);
   htemp->SetBinContent(52,20208);
   htemp->SetBinContent(53,22555);
   htemp->SetBinContent(54,25319);
   htemp->SetBinContent(55,29008);
   htemp->SetBinContent(56,35488);
   htemp->SetBinContent(57,37409);
   htemp->SetBinContent(58,39614);
   htemp->SetBinContent(59,36608);
   htemp->SetBinContent(60,33534);
   htemp->SetBinContent(61,30860);
   htemp->SetBinContent(62,28471);
   htemp->SetBinContent(63,25343);
   htemp->SetBinContent(64,23120);
   htemp->SetBinContent(65,20814);
   htemp->SetBinContent(66,18449);
   htemp->SetBinContent(67,15953);
   htemp->SetBinContent(68,13920);
   htemp->SetBinContent(69,13344);
   htemp->SetBinContent(70,11866);
   htemp->SetBinContent(71,9943);
   htemp->SetBinContent(72,8305);
   htemp->SetBinContent(73,6784);
   htemp->SetBinContent(74,5580);
   htemp->SetBinContent(75,4391);
   htemp->SetBinContent(76,3559);
   htemp->SetBinContent(77,2766);
   htemp->SetBinContent(78,2139);
   htemp->SetBinContent(79,1684);
   htemp->SetBinContent(80,1277);
   htemp->SetBinContent(81,1060);
   htemp->SetBinContent(82,842);
   htemp->SetBinContent(83,629);
   htemp->SetBinContent(84,498);
   htemp->SetBinContent(85,414);
   htemp->SetBinContent(86,284);
   htemp->SetBinContent(87,239);
   htemp->SetBinContent(88,213);
   htemp->SetBinContent(89,139);
   htemp->SetBinContent(90,111);
   htemp->SetBinContent(91,75);
   htemp->SetBinContent(92,40);
   htemp->SetBinContent(93,1);
   htemp->SetEntries(849532);
   htemp->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 849532 ");
   text = ptstats->AddText("Mean  =  90.12");
   text = ptstats->AddText("RMS   =  28.42");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp->SetLineColor(ci);
   htemp->GetXaxis()->SetTitle("col7");
   htemp->GetXaxis()->SetRange(1,100);
   htemp->GetXaxis()->SetLabelFont(42);
   htemp->GetXaxis()->SetLabelSize(0.035);
   htemp->GetXaxis()->SetTitleSize(0.035);
   htemp->GetXaxis()->SetTitleFont(42);
   htemp->GetYaxis()->SetLabelFont(42);
   htemp->GetYaxis()->SetLabelSize(0.035);
   htemp->GetYaxis()->SetTitleSize(0.035);
   htemp->GetYaxis()->SetTitleFont(42);
   htemp->GetZaxis()->SetLabelFont(42);
   htemp->GetZaxis()->SetLabelSize(0.035);
   htemp->GetZaxis()->SetTitleSize(0.035);
   htemp->GetZaxis()->SetTitleFont(42);
   htemp->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.3739542,0.9370168,0.6260458,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("col7 {col1==1}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
