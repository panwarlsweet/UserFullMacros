#
# Simple script to extract the b-tag discriminators for b and light-flavor jets
#
#
#The main idea of script to use discriminator plot to make ROC curve. In the discr. plot calculate efficiency by varying the discriminator
# value on x-axis (ex. (hist integral after discr cut)/ full integral. Do this for signal and background sample and then plot the
# values like a simple graph taking mistag rate on Y axis and b-eff on x-axis.


from ROOT import *


# b-tagger
#bTagger = 'pfCombinedInclusiveSecondaryVertexV2BJetTags'
bTagger = 'pfDeepCSVJetTagsProbB'
# input file
#inputFile = TFile.Open('80_vs_94/Read_root_run2/exerciseII_histos_CSV_QCD_94.root')
inputFile = TFile.Open("/Users/latapanwar/Downloads/output_bEnri.root")

# get 2D b-tag discriminator vs jet pT histograms
#discrVsPt_b    = inputFile.Get(bTagger + '_b')
discrVsPt_b    = inputFile.Get('bTaggingExerciseIISubJets/' + bTagger + '_b')
discrVsPt_udsg = inputFile.Get('bTaggingExerciseIISubJets/' + bTagger + '_udsg')

# make y-axis projections to get 1D discriminator distributions
discr_b    = discrVsPt_b.ProjectionY()
#discr_c    = discrVsPt_c.ProjectionY()
discr_udsg = discrVsPt_udsg.ProjectionY()

I_b=[]
I_c=[]
I_udsg=[]
count=1
i=0.0
while True:
# b-flavor jets
 discr_b.GetXaxis().SetRangeUser(i,1.0)
 print discr_b.Integral()
 I_b.append(discr_b.Integral())
 i=i+0.05
 count+=1
 if(i>=1.0):
  break
print "b_tagging"
print I_b
for j in range(20):
  print I_b[j]/I_b[0],","

"""i=0.0
while True:
# b-flavor jets
 discr_c.GetXaxis().SetRangeUser(i,1.0)
 print discr_c.Integral()
 I_c.append(discr_c.Integral())
 i=i+0.05
 count+=1
 if(i>=1.0):
  break
print "c_tagging"
print I_c
for j in range(20):
  print I_c[j]/I_c[0],","

"""


i=0.0
while True:
# light-flavor jets
 discr_udsg.GetXaxis().SetRangeUser(i,1.0)
 print discr_udsg.Integral()
 I_udsg.append(discr_udsg.Integral())
 i=i+0.05
 count+=1
 if(i>=1.0):
  break
print "udsg-tagging"
print I_udsg
for j in range(20):
  print I_udsg[j]/I_udsg[0],","


print discr_udsg.Integral()
print discr_b.Integral()
#print discr_c.Integral()
# adjust the y-axis range
#discr_udsg.SetMaximum(1.7*discr_b.GetMaximum())
# draw histograms
# close the input file
inputFile.Close()


