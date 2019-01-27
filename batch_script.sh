n=0
s=1
id=1
m=1
max=507   ### number of splitting
job=H1000_1500_ #####change this label
while [ $s -lt $max ]
do
	e=`expr $s + $2 - 1 `
	if [ $e -gt $n ]
	then
		e=$n
        elif [ $id -eq $max ]
        then
                break
	fi
		echo "#!/bin/sh" >> $job$id.sh
                echo "export X509_USER_PROXY=/afs/cern.ch/work/l/lata/HH4b/nonreso/DELPHES/x509up_u103989"  >> $job$id.
sh
		echo "cd /afs/cern.ch/work/l/lata/HH4b/nonreso/CMSSW_9_1_0_pre3/src" >> $job$id.sh 
		echo "eval \`scramv1 runtime -sh\`" >> $job$id.sh
		echo "cd /afs/cern.ch/work/l/lata/HH4b/nonreso/DELPHES/delphes" >> $job$id.sh
		echo "root -l -b -q BGenfilter_HT1000_1500.C'(200, $n, $m, "\"out_$job$id.root\"")'" >> $job$id.sh    #
### change .C file
                n=$m
                m=`expr $m + 1`
		bsub -q 1nh < $job$id.sh    #### change queque according to splitting
		echo "bsub -q 1nh < $job$id.sh"
	s=`expr $e + 1`
	id=`expr $id + 1`
done
