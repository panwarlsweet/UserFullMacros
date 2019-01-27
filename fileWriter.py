#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  fileWriter.py
#  
#  Copyright 2017 P C Tiwari <ptiwari@PCT-Inspiron-5548>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  


import sys, os
"""
data = [line.strip() for line in open("QCD_0PU.txt", 'r')]
for i in data:
   print 'root://cms-xrd-global.cern.ch/'+i
"""
n=0
m=2095
#test='root://cms-xrd-global.cern.ch//store/user/snowmass/noreplica/YR_Delphes/Delphes342pre15/QCD_HT2000toInf_BGenFilter_TuneCUEP8M2T4_14TeV-madgraphMLM-pythia8_200PU/QCD_HT2000toInf_BGenFilter_TuneCUEP8M2T4_14TeV-madgraphMLM-pythia8_'
#for i in range(1,m):
#  for j in range(0,1):
#    test1='"'+test+str(i)+'_'+str(j)+'.root'+'",'
#    print (test1,end='')
 #  print root://se01.indiacms.res.in:1094//store/user/lata/t3store2/Hadron_Calibration/CRAB_PrivateMC/crab_GenSim500/180115_065608/0000/GENSIM1_'+str(m)+'.root'+"',"    
for i in range(0,m):
  print ('./runJobs'+str(i)+'.sh >&runJobs'+str(i)+'.log&')

