from pdf2image import convert_from_path
import pytesseract
from PIL import Image

# Path to your PDF file
pdf_path = './testingScript.pdf'

# Convert PDF pages to images
images = convert_from_path(pdf_path)

# Function to perform OCR on an image and extract text
def ocr_image(image):
    text = pytesseract.image_to_string(image)
    return text

# Performing OCR on the images and storing the text
ocr_results = []
for i, image in enumerate(images):
    text = ocr_image(image)
    ocr_results.append(text)
    print(f"Text from page {i+1}:\n{text}\n")

# Optionally, you can save the OCR results to a text file
with open('output_text.txt', 'w') as f:
    for i, text in enumerate(ocr_results):
        f.write(f"Page {i+1}:\n{text}\n")