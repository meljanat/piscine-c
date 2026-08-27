import os

def make_line(left, right):
    return left + " " * (80 - len(left) - len(right)) + right

def gen_header(filename):
    user = "mel-jana"
    email = "mel-jana@student.1337.ma"
    created = "2026/08/27 02:00:00"
    updated = "2026/08/27 02:00:00"
    
    lines = []
    lines.append("/* " + "*" * 74 + " */")
    lines.append(make_line("/*", "*/"))
    lines.append(make_line("/*", ":::      ::::::::   */"))
    lines.append(make_line(f"/*   {filename}", ":+:      :+:    :+:   */"))
    lines.append(make_line("/*", "+:+ +:+         +:+     */"))
    lines.append(make_line(f"/*   By: {user} <{email}>", "+#+  +:+       +#+        */"))
    lines.append(make_line("/*", "+#+#+#+#+#+   +#+           */"))
    lines.append(make_line(f"/*   Created: {created} by {user}", "#+#    #+#             */"))
    lines.append(make_line(f"/*   Updated: {updated} by {user}", "###   ########.fr       */"))
    lines.append(make_line("/*", "*/"))
    lines.append("/* " + "*" * 74 + " */")
    
    return "\n".join(lines) + "\n"

def process_file(path):
    with open(path, 'r') as f:
        content = f.read()
    
    # Strip all existing headers
    lines = content.split('\n')
    idx = 0
    while idx < len(lines):
        if lines[idx].startswith("/*"):
            end = idx
            while end < len(lines) and not lines[end].endswith("*/"):
                end += 1
            if end < len(lines) and lines[end].endswith("*/"):
                idx = end + 1
            else:
                break
        elif lines[idx].strip() == "":
            idx += 1
        else:
            break
            
    pure_content = "\n".join(lines[idx:])
    
    filename = os.path.basename(path)
    new_content = gen_header(filename) + "\n" + pure_content
    
    with open(path, 'w') as f:
        f.write(new_content)

for d in ['c00', 'c01', 'c02', 'c03', 'c04', 'c05', 'c06', 'c07']:
    for root, _, files in os.walk(d):
        for f in files:
            if f.endswith('.c') or f.endswith('.h'):
                process_file(os.path.join(root, f))
