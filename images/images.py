#! /usr/bin/python3

import re
from pathlib import Path
from PIL import Image, ImageColor, ImageDraw, ImageFont

def remove_pngs():
	for f in Path('./').glob('*.png'):
		f.unlink()

def make_png(filename, text, bgcolor, textcolor, width):
	img_w = width
	img_h = 54
	font = ImageFont.truetype("verdana.ttf", 24)
	img = Image.new('RGB', (200, 100), ImageColor.getrgb(bgcolor))
	draw = ImageDraw.Draw(img)
	text_w, text_h = draw.textsize(text, font=font)
	if img_w == 0:
		img_w = 54 * ((text_w + 27) // 54 + 1)
	img = Image.new('RGB', (img_w, img_h), ImageColor.getrgb(bgcolor))
	draw = ImageDraw.Draw(img)
	draw.text(((img_w - text_w) / 2, (img_h - text_h) / 2), text, font=font, fill=ImageColor.getrgb(textcolor))
	img.save(filename)

def make_pngs(pat, line):
	m = pat.findall(line)
	for t in m:
		filename = t[0] + '_' + t[1] + t[2] + t[3] + '_' + t[4] + '.png'
		text = t[1]
		t3 = t[3].replace('z', '.')
		if t[2] == '--':
			text = text + '(' + t3 + ')'
		elif t[2] == '-':
			text = text + '[' + t3 + ']'
		else:
			text = text + t[3]
		bgcolor = '#' + t[4]
		textcolor = '#000000'
		width = 0
		if t[0] == 'T':
			width = 27
		elif t[0] == 'U':
			textcolor = '#ffffff'
			width = 54
		elif t[0] == 'V':
			textcolor = '#ffffff'
			width = 108
		elif t[0] == 'W':
			textcolor = '#ffffff'
			width = 162
		elif t[0] == 'X':
			width = 54
		elif t[0] == 'Y':
			width = 108
		elif t[0] == 'Z':
			width = 162
		make_png(filename, text, bgcolor, textcolor, width)

if __name__ == '__main__':
	remove_pngs()
	pat = re.compile(r'([T-Z])_([0-9A-Za-z]*)(-*)([0-9z]*)_([0-9a-f]+)\.png')
	with open('../README.md') as f:
		for line in f:
			make_pngs(pat, line)

