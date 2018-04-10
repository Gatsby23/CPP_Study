import matplotlib.pyplot as plt
import numpy as np

# make data
boxcell_x = np.concatenate([np.arange(0,4)*1.5+4.2, np.arange(0,2)*1.5+7.2])#np.array([])
boxcell_y = np.concatenate([np.ones(4)*2.6, np.ones(2)*4.1])

circell_x = np.array([2.7, 4.2, 5.7, 7.2, 8.7])
circell_y = np.array([2.6, 4.1, 4.1, 5.6, 5.6])

dotcell_x = np.array([2.7, 4.2, 2.7, 4.2, 5.7, 7.2, 8.7])
dotcell_y = np.array([5.6, 5.6, 7.2, 7.2, 7.2, 7.2, 7.2])

shodow_x = np.array([4.2, 4.2, 5.7, 5.8])
shodow_y = np.array([5.6, 7.2, 7.2, 5.5])

crosscell_x = np.array([2.5, 5.55])
crosscell_y = np.array([4.3, 5.89])

sdotcell_x = np.array([5.3, 5.8])
sdotcell_y = np.array([6.3, 5.5])

# plot marks
plt.plot(circell_x,circell_y, marker=r'$\bigodot$', markersize=22,
        linewidth=0, alpha=0.6, color='k', label='Gost-Cell')
plt.plot(boxcell_x,boxcell_y, marker=r'$\boxdot$', markersize=22,
        linewidth=0, alpha=0.6, color='k', label='Solid-Cell')
plt.plot(dotcell_x,dotcell_y, marker='o', markersize=12, linewidth=0,
        alpha=0.5, color='k', label='Fluid-Cell')
plt.plot(crosscell_x,crosscell_y, marker=r'$\oplus$', markersize=8,
        linewidth=0, label='Fresh-Cell')
plt.plot(sdotcell_x,sdotcell_y, marker=r'$\circ$', markersize=8,
        linewidth=1, alpha=0.8, color='k')
# plot shodow
plt.fill(shodow_x, shodow_y, linewidth=0, alpha=0.2, color='k')

plt.annotate('BI', xy=(5.8, 5.5), xytext=(+5, +5), textcoords='offset points')
plt.annotate('IP', xy=(5.3, 6.3), xytext=(+5, +5), textcoords='offset points')

# plot curve
plt.annotate(r'$n+1$',
         xy=(9.6, 6.5), xycoords='data',
         xytext=(1.4, 2.4), textcoords='data', fontsize=16,
         arrowprops=dict(arrowstyle="-", connectionstyle="arc3,rad=-.2"))
plt.annotate(r'$n$',
         xy=(9.4, 6.9), xycoords='data',
         xytext=(1.4, 3.5), textcoords='data', fontsize=16,
         arrowprops=dict(arrowstyle="-", connectionstyle="arc3,rad=-.2",
             linestyle='dashed'))
plt.grid(True, color='k', linewidth=2)

# set the figure style
ax = plt.gca()

ax.set_xticks(np.arange(0,10,1.5)+0.4)
ax.set_yticks(np.arange(0,10,1.5)+0.4)

ax.spines['right'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['left'].set_color('none')
ax.spines['top'].set_color('none')

plt.axis('scaled')
plt.xlim(0.5,10.5)
plt.ylim(-1,9)
plt.tick_params(labelbottom='off', labelleft='off', left='off', right='off',
        bottom='off', top='off')

# add the legend
ax.legend(loc='lower center', handlelength=2.3, handletextpad=1, labelspacing=1,
        ncol=2,mode="expand",borderpad=1, fancybox=True)
plt.show()
