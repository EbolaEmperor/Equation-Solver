import Tkinter as tk
import tkMessageBox
import commands

def clickMe():
    equation = entry1.get()
    eps = entry2.get()
    equation = equation.replace('(','\(')
    equation = equation.replace(')','\)')
    cmd = "./algo "+equation+" "+eps
    rtn, ans = commands.getstatusoutput(cmd)
    tkMessageBox.showinfo('Solved!',ans)


win = tk.Tk()
win.geometry("300x150")
win.title("Eqution-Solver")

label1=tk.Label(win, text="Input Equation:")
label1.grid(column=1, row=1)
entry1=tk.Entry(win,width=35,bg="white",fg="black")
entry1.grid(column=1, row=2)

label2=tk.Label(win, text="EPS demand:")
label2.grid(column=1, row=3)
entry2=tk.Entry(win,width=35,bg="white",fg="black")
entry2.grid(column=1, row=4)

action = tk.Button(win, text="Solve!", command=clickMe)
action.grid(column=1, row=5)

win.mainloop()